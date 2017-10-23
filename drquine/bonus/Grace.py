import os
"""
comment1
"""
if os.path.exists("Grace_kid.py") and not os.access("Grace_kid.py", os.W_OK):
    exit()
fp = open("Grace_kid.py", "w");
x = 'import os\n"""\ncomment1\n"""\nif os.path.exists("Grace_kid.py") and not os.access("Grace_kid.py", os.W_OK):\n    exit()\nfp = open("Grace_kid.py", "w");\nx = {!r};\nfp.write(x.format(x));\nfp.close();\n';
fp.write(x.format(x));
fp.close();
