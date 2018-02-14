SRC = analyse-besoins
all:
	pdflatex $(SRC).tex
	bibtex $(SRC)
	pdflatex $(SRC).tex
	pdflatex $(SRC).tex
clean:
	rm *.aux *.log *.bbl *.blg
