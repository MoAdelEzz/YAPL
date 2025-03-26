run:
	bison --yacc -d parser.y
	flex lexer.l
	gcc -o compiler y.tab.c lex.yy.c utils.c
	 

lex: 
	flex lexer.l
	gcc -g -o out/lexer lex.yy.c
	./out/lexer

parser:
	bison --yacc -d parser.y
	gcc -g -o out/parser parser.tab.c
	./out/parser