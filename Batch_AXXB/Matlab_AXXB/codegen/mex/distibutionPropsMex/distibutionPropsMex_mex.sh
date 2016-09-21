MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/roma/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for distibutionPropsMex" > distibutionPropsMex_mex.mki
echo "CC=$CC" >> distibutionPropsMex_mex.mki
echo "CFLAGS=$CFLAGS" >> distibutionPropsMex_mex.mki
echo "CLIBS=$CLIBS" >> distibutionPropsMex_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> distibutionPropsMex_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> distibutionPropsMex_mex.mki
echo "CXX=$CXX" >> distibutionPropsMex_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> distibutionPropsMex_mex.mki
echo "CXXLIBS=$CXXLIBS" >> distibutionPropsMex_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> distibutionPropsMex_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> distibutionPropsMex_mex.mki
echo "LD=$LD" >> distibutionPropsMex_mex.mki
echo "LDFLAGS=$LDFLAGS" >> distibutionPropsMex_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> distibutionPropsMex_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> distibutionPropsMex_mex.mki
echo "Arch=$Arch" >> distibutionPropsMex_mex.mki
echo OMPFLAGS= >> distibutionPropsMex_mex.mki
echo OMPLINKFLAGS= >> distibutionPropsMex_mex.mki
echo "EMC_COMPILER=gcc" >> distibutionPropsMex_mex.mki
echo "EMC_CONFIG=optim" >> distibutionPropsMex_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f distibutionPropsMex_mex.mk
