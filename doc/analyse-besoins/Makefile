TEX = pdflatex
BIB = bibtex

PDF = analyse-besoins.pdf
TEXFILE = analyse-besoins.tex

all: $(PDF)

%.pdf : %.tex
	$(TEX) $^

.PHONY: clean

clean:
	rm -rf $(PDF) *.aux *.log *.toc *.out *.fls *.fdb_latexmk *.synctex.gz  rm -rf *.bbl *.blg
