script="one_folder.sh"

for folder in */
do
  echo $folder
  $CLONESCRIPTS/$script $folder
done

echo finished!
