"""
    This is the setup file for pyfib.c. It is needed to run the cfib cell in
    the ipython notebook.
    Compile and install in your environment with:
    `python setup.py install`
"""

from distutils.core import setup, Extension

def main():
    setup(
        name="cfib",
        version="0.0.1",
        description="Python interface for a C fibonacci function.",
        author="ecowley",
        author_email="erik@stromsy.com",
        ext_modules=[Extension("cfib", ["pyfib.c",]),],
    )

if __name__ == "__main__":
    main()
