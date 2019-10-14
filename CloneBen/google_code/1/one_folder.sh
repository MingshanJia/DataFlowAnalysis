argetFolder=$1

script="single_run.sh"
curDir=`pwd`

cd $TargetFolder
mkdir Outputs
Suffix='cpp'
for i in `find . -name '*.cpp'`
do
   $CLONESCRIPTS/$script $i
done

echo Analysis finished!
