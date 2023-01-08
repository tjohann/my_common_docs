#
# LGPL
# (c) 2023, thorsten.johannvorderbrueggen@t-online.de
#

main = pattern

MODULES = $(shell ls -d */ | cut -f1 -d'/')

.PHONY: all clean

all:
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean:
	rm -f *~
	rm -f *.aux
	rm -f *.dvi
	rm -f *.idx
	rm -f *.ilg
	rm -f *.ind
	rm -f *.log
	rm -f *.toc
	rm -f *.ps
	rm -f *.bbl
	rm -f *.blg
	rm -f *.out

	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

distclean: clean

#
# my stuff around my arch pattern and sys-eng papers
#
pics: overview

overview: overview.gv
	dot -Tpng overview.gv -o overview.png

latex: pattern

pattern: pattern.tex
	pdflatex ${main}.tex
	makeindex ${main}
#	biber ${main}
	pdflatex ${main}.tex
	pdflatex ${main}.tex
	pdflatex ${main}.tex

writing: pics latex
