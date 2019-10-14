TargetFolder=$1

script="single_run.sh"
curDir=`pwd`

cd $TargetFolder
mkdir Outputs
for i in `find . -name '*.cpp'`
do
   $CLONESCRIPTS/$script $i
done
cd ..

echo Analysis finished!
