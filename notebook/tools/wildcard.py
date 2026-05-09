import glob
import sys
import os

# Get path from command-line argument, default to current directory
path = sys.argv[1] if len(sys.argv) > 1 else "."

# Collect all .c and .cpp files directly in the specified directory
source_files = glob.glob(os.path.join(path, "*.c")) + glob.glob(
    os.path.join(path, "*.cpp")
)

# On Apple platforms, also include Objective-C and Objective-C++ files
if sys.platform == "darwin":
    source_files += glob.glob(os.path.join(path, "*.m")) + glob.glob(
        os.path.join(path, "*.mm")
    )

# Print each file name with the directory prefix
for file in source_files:
    print(os.path.basename(file))