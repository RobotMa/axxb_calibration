MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/rpk/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for batchEDSolve" > batchEDSolve_mex.mki
echo "CC=$CC" >> batchEDSolve_mex.mki
echo "CFLAGS=$CFLAGS" >> batchEDSolve_mex.mki
echo "CLIBS=$CLIBS" >> batchEDSolve_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> batchEDSolve_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> batchEDSolve_mex.mki
echo "CXX=$CXX" >> batchEDSolve_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> batchEDSolve_mex.mki
echo "CXXLIBS=$CXXLIBS" >> batchEDSolve_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> batchEDSolve_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> batchEDSolve_mex.mki
echo "LD=$LD" >> batchEDSolve_mex.mki
echo "LDFLAGS=$LDFLAGS" >> batchEDSolve_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> batchEDSolve_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> batchEDSolve_mex.mki
echo "Arch=$Arch" >> batchEDSolve_mex.mki
echo OMPFLAGS= >> batchEDSolve_mex.mki
echo OMPLINKFLAGS= >> batchEDSolve_mex.mki
echo "EMC_COMPILER=gcc" >> batchEDSolve_mex.mki
echo "EMC_CONFIG=optim" >> batchEDSolve_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f batchEDSolve_mex.mk
