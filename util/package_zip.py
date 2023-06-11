# Me:      "Can we use Jenkins"
# Also me: "We have Jenkins at home"
#
# The Jenkins at home:
print("Jerkins file packer - 'its free gratis!'");

import os
import pathlib
import sys
import zipfile

# Get arguments

mode      = "Release"
config    = "Release"
info_file = ""
out       = ""

for arg in sys.argv[1:]:
  if not ":" in arg:
    print("Bad argument: " + arg)
    
  (command, value) = arg.split(":", 1)
  
  if command == "mode":
    mode = value
  elif command == "config":
    config = value
  elif command == "info":
    info_file = os.path.realpath(value)
  elif command == "out":
    out = os.path.realpath(value)
    
bin_folder = os.path.realpath(os.path.dirname(info_file) + "/bin/" + config)
    
print("Mode : " + mode);
print("Info : " + info_file);
print("Bin  : " + bin_folder);
print("Out  : " + out);
    
# Read file

executables = []

acceptable_executable_formats = [ ".exe", ".dll" ]
if mode == "Debug":
  acceptable_executable_formats += [ ".pdb" ]

with open(info_file, 'r') as f:
  info_data = f.readlines()
  
for line in map(str.strip, info_data):
  if len(line) == 0:
    continue

  if not ":" in line:
    print("Bad argument: " + line)
    
  (command, value) = map(str.strip, line.split(":", 1))
  
  if command == "executable":
    executables.append(value)
    
# Process

pathlib.Path(os.path.dirname(out)).mkdir(parents=True, exist_ok=True)

print("Writing to " + out)
with zipfile.ZipFile(out, 'w', zipfile.ZIP_DEFLATED) as zipf:
  # Add executables
  for root, dirs, files in os.walk(bin_folder):
    for file in files:
      if pathlib.Path(file).suffix not in acceptable_executable_formats:
        continue
      zipf.write(os.path.join(root, file), file)

print("Done")