compiler: lalr1.y lalr1.l
	flex lalr1.l
	bison -d -t lalr1.y
	g++ lex.yy.c lalr1.tab.c
lalr1.y:
	echo "Bison parser file doesn't exist"
lalr1.l: 
	echo "Flex lexer file doesn't exist"