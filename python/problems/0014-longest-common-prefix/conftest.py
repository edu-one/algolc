# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

import sys
from pathlib import Path

_problem_dir = str(Path(__file__).parent)

# Ensure this problem's directory is first so local imports resolve correctly
if _problem_dir in sys.path:
    sys.path.remove(_problem_dir)
sys.path.insert(0, _problem_dir)

# Invalidate any cached 'solution' module so Python loads from this directory
if "solution" in sys.modules:
    del sys.modules["solution"]
