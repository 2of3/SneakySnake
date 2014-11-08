from distutils.core import setup, Extension

module1 = Extension('uniplug',
                    sources = ['Main.cpp'])

setup (name = 'UniplugPackage',
       version = '1.0',
       description = 'This is a demo package',
	   author = 'FUSEEProjectTeam',
	   url = 'https://fusee3d.org',
       ext_modules = [module1])