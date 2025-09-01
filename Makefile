MARKDOWN = markdown

normal: readme.md
	$(MARKDOWN) readme.md > index.html
