all: gaussian_blur.pdf

gaussian_blur.pdf: gaussian_blur.tex
	mkdir -p build 2>&1 > /dev/null
	pdflatex -output-directory build gaussian_blur.tex

clean:
	rm -rf build
