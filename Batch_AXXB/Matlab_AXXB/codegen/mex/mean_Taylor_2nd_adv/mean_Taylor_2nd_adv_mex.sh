MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/roma/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for mean_Taylor_2nd_adv" > mean_Taylor_2nd_adv_mex.mki
echo "CC=$CC" >> mean_Taylor_2nd_adv_mex.mki
echo "CFLAGS=$CFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "CLIBS=$CLIBS" >> mean_Taylor_2nd_adv_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "CXX=$CXX" >> mean_Taylor_2nd_adv_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "CXXLIBS=$CXXLIBS" >> mean_Taylor_2nd_adv_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "LD=$LD" >> mean_Taylor_2nd_adv_mex.mki
echo "LDFLAGS=$LDFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> mean_Taylor_2nd_adv_mex.mki
echo "Arch=$Arch" >> mean_Taylor_2nd_adv_mex.mki
echo OMPFLAGS= >> mean_Taylor_2nd_adv_mex.mki
echo OMPLINKFLAGS= >> mean_Taylor_2nd_adv_mex.mki
echo "EMC_COMPILER=gcc" >> mean_Taylor_2nd_adv_mex.mki
echo "EMC_CONFIG=optim" >> mean_Taylor_2nd_adv_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f mean_Taylor_2nd_adv_mex.mk
