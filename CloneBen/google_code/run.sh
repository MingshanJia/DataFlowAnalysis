script="all_folders.sh"

for folder in */
   do 
     echo processing $folder
     cd $folder
     ls
     $CLONESCRIPTS/$script
     cd ../
   done
echo finished!

