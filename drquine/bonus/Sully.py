import os
import subprocess
i = 5
if i <= 0:
    exit()
if "Sully.py" not in __file__:
    i -= 1
filename = "Sully_" + str(i) + ".py"
if os.path.exists(filename) and not os.access(filename, os.W_OK):
    exit()
fp = open(filename, "w");
x = 'import os\nimport subprocess\ni = {:d}\nif i <= 0:\n    exit()\nif "Sully.py" not in __file__:\n    i -= 1\nfilename = "Sully_" + str(i) + ".py"\nif os.path.exists(filename) and not os.access(filename, os.W_OK):\n    exit()\nfp = open(filename, "w");\nx = {!r};\nfp.write(x.format(i,x))\nfp.close()\nsubprocess.call(["python",filename])\n';
fp.write(x.format(i,x))
fp.close()
subprocess.call(["python",filename])
