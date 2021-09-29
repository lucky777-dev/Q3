# If you ever add a chapter, don't forget to add it here.
CHAPTERS := $(addprefix ch, $(shell seq 0 13))

# As a general rule, it is best to avoid using spaces in filenames.
# Face the consequences:
# Q is merely a double quote. Nothing hidden here.
Q:="
#" # This silly line is important for editors' string parsers.
findarg = $(addprefix $(Q), $(addsuffix $(Q), Ch.+$(1)+*))
# This function returns the chapter path from the chapter number.
chapterpath = $(shell find . \
	        -name $(subst +, ,$(call findarg,$(1))) -print -quit)

.PHONY: all slides handouts clean

all: $(CHAPTERS)

ch%:
	$(MAKE) -C "$(call chapterpath,$*)"

ch%-slides:
	$(MAKE) -C "$(call chapterpath,$*)" slides.pdf

ch%-handout:
	$(MAKE) -C "$(call chapterpath,$*)" slides-handout.pdf

ch%-clean:
	$(MAKE) -C "$(call chapterpath,$*)" clean

slides: $(addsuffix -slides, $(CHAPTERS))

handouts: $(addsuffix -handout, $(CHAPTERS))

clean: $(addsuffix -clean, $(CHAPTERS))

new_chapter:
	mkdir "Ch. XX - YYY" > /dev/null
	cp common/cp/slides.tex "Ch. XX - YYY" > /dev/null
	ln -s ../common/Makefile.common "Ch. XX - YYY"/Makefile > /dev/null
	ln -s ../common/slides-handout.tex "Ch. XX - YYY"/slides-handout.tex > /dev/null   
