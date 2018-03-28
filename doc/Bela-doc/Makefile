TEX = pdflatex

PDF = documentation_Bela.pdf
TEXFILE = documentation_Bela.tex

all: $(PDF)

%.pdf : %.tex
	$(TEX) $^

.PHONY: clean

clean:
	rm -rf $(PDF) *.aux *.log *.toc *.out
