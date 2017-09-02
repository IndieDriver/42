def function():
    x = 'def function():\n    x = {!r};\n    print(x.format(x));\n"""\ncomment1\n"""\ndef main():\n    """\n    comment2\n    """\n    function();\nmain();';
    print(x.format(x));
"""
comment1
"""
def main():
    """
    comment2
    """
    function();
main();
