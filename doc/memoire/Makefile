INC_DIR = ../

TEX = pdflatex
BIB = bibtex

PDF = memoire.pdf
TEXFILE = memoire.tex

all: $(PDF)

$(PDF): $(TEXFILE)
	@$(TEX) $^
	@$(TEX) $^	#This command is used twice to solve tableofcontents issues

.PHONY: clean

clean:
	rm -rf $(PDF) *.aux *.log *.toc *.out
