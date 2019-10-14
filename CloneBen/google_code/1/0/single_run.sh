#usage: ./single_run.sh filename

TestFile=$1

CLANGFLAG='-c -emit-llvm -fno-discard-value-names'

### wpa command
TNAME=wpa
EXEFILE=$PTABIN/$TNAME
Clean="$PTATEST/clean.sh"

Suffix='cpp'
FileName=`basename $TestFile .$Suffix`

$CLANGCPP $CLANGFLAG $TestFile -o $FileName.bc

BCFile=$FileName.bc
TxtOutput=$FileName'_ifds'.txt
SVFGDOT=$FileName'_svfg'.dot
CGDOT=$FileName'_cg'.dot
SVFGPNG=$FileName'_svfg'.png
CGPNG=$FileName'_cg'.png

$LLVMDIS $BCFile

WPATy=-sifds
DumpTy=-dump-svfg
DumpTy2=-dump-callgraph

echo ============== analyzing $FileName.$Suffix ==========================
$EXEFILE $WPATy $DumpTy $DumpTy2 -stat=0 $BCFile>&Outputs/$TxtOutput
dot -Tpng svfg_initial.dot -o $SVFGPNG
dot -Tpng callgraph_final.dot -o $CGPNG
mv svfg_initial.dot $SVFGDOT
mv callgraph_final.dot $CGDOT
echo ============== analysis finished ==========================

