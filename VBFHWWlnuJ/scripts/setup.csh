setenv THISDIR `pwd`

setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${THISDIR}/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${THISDIR}/NtuplePackage/lib
# For CLHEP
setenv CLHEPSYS /afs/cern.ch/sw/lcg/external/clhep/2.1.3.1/x86_64-slc5-gcc46-opt/
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${CLHEPSYS}/lib

if (${?DYLD_LIBRARY_PATH}) then
setenv DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH}:${THISDIR}/lib
setenv DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH}:${THISDIR}/NtuplePackage/lib
endif



setenv PATH ${PATH}:${THISDIR}/bin
setenv PATH ${PATH}:${CLHEPSYS}/bin
setenv PATH ${PATH}:${THISDIR}/NtuplePackage/bin

setenv NTUPLEPKGINCLUDE ${THISDIR}/NtuplePackage/interface
setenv NTUPLEPKGLIB ${THISDIR}/NtuplePackage/lib

setenv VBFHWWlnuJ ${THISDIR}/
