#!/usr/bin/env python
# -*- coding: utf-8 -*-
""" 
.. examplepre-block:: python setup.py build --build-base=.

Description
-----------
To build use as the following
python setup.py build --build-base=.

To install
python setup.py install

.. examplepost-block:: from youbot import * in python shell
""" 
from distutils.core import setup
from distutils.extension import Extension
import os,sys,shutil

current_dir = os.getcwd()
self_headers = os.path.join(current_dir,'bindings')

try:
   YOUBOT_HOME = os.environ["YOUBOT_HOME"]
except KeyError: 
   print "Please set the environment variable YOUBOT_HOME"
   print "export YOUBOT_HOME=/pathto/youbot_driver in bashrc"
   sys.exit(1)

 
setup(name="PackageName",
    ext_modules=[
 	
        Extension("youbot", ["binding/binding.cpp"],
        include_dirs=[YOUBOT_HOME,os.path.join(YOUBOT_HOME,'soem/src'),os.path.join(current_dir,'binding')],
	runtime_library_dirs = [os.path.join(current_dir,'lib')],
        libraries = ['boost_python','YOUBOT_HOME/lib/YouBotDriver'])
    ])

#Causes error when trying to install. Have to deal with the name of the folder
#shutil.move('lib.linux-x86_64-2.7','lab')
