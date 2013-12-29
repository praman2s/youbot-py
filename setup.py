#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (C) 2013-2014 Praveen Ramanujam (praveen.ramanujam@locomotec.com)
#
#  All rights reserved.
#  Redistribution and use in source and binary forms, with or without modification,
#  are permitted provided that the following conditions are met:
#  * Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright notice, this
#    list of conditions and the following disclaimer in the documentation and/or
#    other materials provided with the distribution.
#  * Neither the name of the Hochschule Bonn-Rhien-Sieg or Locomotec nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
#  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
#  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"""Build and install setup for python interface for youbot.

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
