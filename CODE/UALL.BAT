@echo off
make unren
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 *.c
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 *.h
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 *.mak
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 eng\*.txt
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 eng\*.ini
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 eng\*.eng
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 *.app
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 scr\*.scr
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 makefile
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 lmkfile
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\*.lbm
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\fin\*.anm
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\intro\*.anm
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\crd\*.crd
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\fonts\*.lbm
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 art\anim\*.anm
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\adl\*.adl
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\adl\*.tan
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\pcs\*.pcs
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\xmi\*.xmi
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\voc\*.voc
ci -YG:\PROJECTS\DUNE\CODE\RCS.RC -mChanges -l %1 %2 %3 music\c55\*.c55

REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.c
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.h
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.mak
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.txt
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.app
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg *.scr
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg makefile
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg lmkfile
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg art\*.lbm
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg music\*.adl
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg music\*.snd
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg music\*.xmi
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg music\*.voc
REM put -MChanges -N -L -CG:\projects\dune\code\vcs.cfg art\fin\*.fin



