INC_DIR = ../

TEX = pdflatex
BIB = bibtex

PDF = memoire.pdf
TEXFILE = memoire.tex

all: $(PDF)

$(PDF): $(TEXFILE)
	@$(TEX) $^
	$(BIB) memoire
	@$(TEX) $^	#This command is used twice to solve tableofcontents issues

.PHONY: clean

clean:
	rm -rf $(PDF) *.aux *.log *.toc *.out *.fls *.fdb_latexmk *.synctex.gz
	rm -rf *.bbl *.blg
