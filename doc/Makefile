INC_DIR = ../

TEX = pdflatex
BIB = bibtex

PDF = memoire.pdf documentation_Bela.pdf
TEXFILE = memoire.tex

all: $(PDF)

%.pdf : %.tex
	$(TEX) $^


.PHONY: clean

clean:
	rm -rf $(PDF) *.aux *.log *.toc *.out
