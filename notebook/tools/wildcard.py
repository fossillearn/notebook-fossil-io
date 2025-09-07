import glob
import sys
import os

# Get path from command-line argument, default to current directory
path = sys.argv[1] if len(sys.argv) > 1 else "."

# Ensure the path ends with a slash for glob
search_path = os.path.join(path, "*")

# Collect all .c and .cpp files directly in the specified directory
source_files = glob.glob(os.path.join(search_path, "*.c")) + glob.glob(os.path.join(search_path, "*.cpp"))

# On Apple platforms, also include Objective-C and Objective-C++ files
if sys.platform == "darwin":
    source_files += glob.glob(os.path.join(search_path, "*.m")) + glob.glob(os.path.join(search_path, "*.mm"))

# Print each file name with the directory prefix
for file in source_files:
    print(file)
