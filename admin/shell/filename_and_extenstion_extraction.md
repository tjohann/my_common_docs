extract filename or filename extension with bash
================================================

see https://www.tomek.cedro.info/bash-filename-and-extenstion-extraction/


filename=$(basename -- "$fullfile")
extension="${filename##*.}"
filename="${filename%.*}"
