#!/usr/bin/env python3
"""
Does clang-format checks on the given source file

Copyright (C) 2019  Qian Yu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""

import os
import sys
import argparse
import subprocess
import difflib

if __name__ == "__main__":
    cmd = argparse.ArgumentParser(description=__doc__)
    cmd.add_argument(
        "--build-path", required=True, help="Directory containing compile_commands.json"
    )
    cmd.add_argument(
        "--clangformatbin", required=True, help="Path to clang-format binary"
    )
    cmd.add_argument("files", nargs="+", help="Source files to check")

    args = cmd.parse_args()

    # clang-format
    for fileName in args.files:
        clangformat = [args.clangformatbin, fileName]
        print(" ".join(clangformat))
        output = subprocess.check_output(clangformat)

        with open(fileName, "r") as fd:
            left = fd.read().splitlines()
            right = output.decode("utf-8").splitlines()
            diffs = list(
                difflib.unified_diff(left, right, fromfile=fileName, tofile="formatted")
            )
            for line in diffs:
                print(line, file=sys.stderr)
            if diffs:
                sys.exit("clang-format check failed for {}".format(fileName))

    # check generated code
    genCmd = os.path.join(os.path.dirname(__file__), "gen-integral-switch.py")
    generated = subprocess.check_output(
        [genCmd, "--clangformatbin", args.clangformatbin, "32"]
    )
    integralswitch = os.path.join(
        os.path.dirname(os.path.dirname(__file__)), "include", "integral_switch.h"
    )
    with open(integralswitch, "r") as fd:
        left = fd.read().splitlines()
        right = generated.decode("utf-8").splitlines()
        diffs = list(
            difflib.unified_diff(
                left, right, fromfile=integralswitch, tofile="gen-integral-switch.py"
            )
        )
        for line in diffs:
            print(line, file=sys.stderr)
        if diffs:
            sys.exit(
                "gen-integral-switch.py generated diffs. Did you forget to run it?"
            )
