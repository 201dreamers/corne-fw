"""
This script parses .vil files, generated by the Vial, gets layout from it
and makes it pretty printed and ready to paste into qmk keymap.c

=> !NOTE: It's made for CORNE keyboard. I think it could work with split
keyboards, but not with the regular ones.

=> Output example:

Layout 0:
KC_TAB     , KC_Q       , KC_W       , KC_E       , KC_R       , KC_T       ,
KC_LCTRL   , KC_A       , KC_S       , KC_D       , KC_F       , KC_G       ,
KC_LALT    , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B       ,
                                       KC_LGUI    , KC_LSHIFT  , FN_MO23    ,

KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       , KC_BSPACE  ,
KC_H       , KC_J       , KC_K       , KC_L       , KC_SCOLON  , KC_QUOTE   ,
KC_N       , KC_M       , KC_COMMA   , KC_DOT     , KC_SLASH   , KC_ENTER   ,
FN_MO13    , KC_SPACE   , KC_ESCAPE  ,
=====

Just copy the key codes and paste it into the 'LAYOUT_split_3x6_3()' macro.
There may be some errors in the output. You will see it during compilation
of the qmk firmware, but mostly it works.

Rewrite this script as you want or need :)
"""

import json
from os import PathLike
from argparse import ArgumentParser, Namespace
from pathlib import Path
from itertools import chain
from typing import Iterable


VialLayout = Iterable[Iterable[str | int]]
VialKeymap = Iterable[VialLayout]


def parse_args() -> Namespace:
    """Creates parser for commandline arguments.
    Rerurns parsed args.
    """
    parser = ArgumentParser(
        prog=".vil parser",
        description="Parses Vial files and returns a valid `c` array for qmk."
    )
    parser.add_argument("filename")
    return parser.parse_args()


def get_keymap_from_vil_file(vil_file: PathLike) -> VialKeymap:
    with open(vil_file, "r") as fobj:
        return json.load(fobj)["layout"]


def remove_non_keyname_items(keymap: VialKeymap) -> VialKeymap:
    """Removes -1 from the keymap."""
    filtered_keymap = []
    for layout in keymap:
        filtered_keymap.append(
            tuple(
                tuple(filter(lambda x: x != -1, row))
                for row in layout
            )
        )

    return filtered_keymap


def get_max_length_of_keyname(keymap: VialKeymap) -> int:
    """Returns lenght of the longest keycode in the keymap.
    It's used to print properly aligned table.
    """
    # Convert nested lists into one flat list
    flat_keymap_list = chain.from_iterable(
        chain.from_iterable(keymap))

    # Remove all non-string elements and key duplicates
    key_names = set(map(
        str,
        flat_keymap_list
    ))

    # Get length of an element with the longest name
    return len(max(key_names, key=len))


def print_keymap_for_c_code(keymap: VialKeymap) -> None:
    """Outputs pretty aligned keycodes that could be copied and pasted into
    your keymap.c
    """
    max_keyname_length = get_max_length_of_keyname(keymap)
    first_key_template = f"{{:>{max_keyname_length}}},"
    key_template = f" {first_key_template}"

    for layout_index, layout in enumerate(keymap):

        print(f"\n=> Layout {layout_index}:\n")
        num_of_rows = len(layout) // 2

        for row_index in range(num_of_rows):
            left_row_keynames = layout[row_index]
            # Right side row need to be reversed, as Vial saves them backwards
            right_row_keynames = layout[row_index + num_of_rows][::-1]

            # Create template for row and fill it with keynames
            row_template = (
                f"{first_key_template}"
                f"{key_template * (len(left_row_keynames) - 1)}"
                "  "
                f"{first_key_template}"
                f"{key_template * (len(right_row_keynames) - 1)}"
            )
            row = row_template.format(*left_row_keynames, *right_row_keynames)

            # If it's last row of the keyboard, it has less keys than
            # the previous ones, so adding more spaces on the left to align
            if row_index + 1 == num_of_rows:
                len_difference = \
                    len(layout[row_index - 1]) - len(left_row_keynames)
                shift_from_line_start = \
                    " " * (max_keyname_length * len_difference
                           + 2 * len_difference)
                row = f"{shift_from_line_start}{row[:-1]}\n"

            print(row)
        print("-----")


if __name__ == "__main__":
    filename = parse_args().filename

    keymap = get_keymap_from_vil_file(Path(filename))
    keymap = remove_non_keyname_items(keymap)

    print_keymap_for_c_code(keymap)