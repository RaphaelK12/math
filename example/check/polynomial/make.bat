@rem !/bin/msdos
@
@echo %cd%
@cd solve
@call make.bat
@cd ..
@
@cl /EHsc  -I../../../src evaluate.cpp
@cl /EHsc  -I../../../src normalize.cpp
@cl /EHsc  -I../../../src optimize.cpp
@

