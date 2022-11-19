CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11
GFLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lcheck 
UBUNTU = -lrt -lpthread -lm -lsubunit
UFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
SOURCE = $(wildcard $(PROJECTNAME)_backend/s21_*.c)
PROJECTNAME = 3D_Viewer

rebuild: clean all

all: $(PROJECTNAME).a tests check gcov_report install dist dvi

install:
	@cd $(PROJECTNAME)_interface/ && qmake && make && make clean && rm Makefile
	@mv $(PROJECTNAME)_interface/$(PROJECTNAME)_qt.app/Contents/MacOS/$(PROJECTNAME)_qt $(PROJECTNAME)
	@rm -rf $(PROJECTNAME)_interface/$(PROJECTNAME)_qt.app
	@./$(PROJECTNAME)

uninstall:
	@rm -rf $(PROJECTNAME)

clean:
	@rm -rf *.o && rm -rf *.gcno
	@rm -rf *.a && rm -rf *.gcda
	@rm -rf *.info && rm -rf *.gcov
	@rm -rf ./test && rm -rf ./gcov_report
	@rm -rf ./report/
	@rm -rf test.out
	@rm -rf test.out.dSYM
	@rm -rf $(PROJECTNAME).dvi
	@rm -rf $(PROJECTNAME).tgz

init_settings:
	@echo "line_width = 1.000000" > $(PROJECTNAME)_interface/settings.txt
	@echo "point_size = 5.000000" >> $(PROJECTNAME)_interface/settings.txt
	@echo "dotted_line = 0" >> $(PROJECTNAME)_interface/settings.txt
	@echo "type_of_point = 0" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_line_r = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_line_g = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_line_b = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_back_r = 42" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_back_r = 43" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_back_g = 42" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_point_g = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_point_b = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "color_of_point_b = 255" >> $(PROJECTNAME)_interface/settings.txt
	@echo "projection = 0" >> $(PROJECTNAME)_interface/settings.txt

dvi:
	@touch $(PROJECTNAME).dvi
	@echo "In this project we implemented an extended version of the usual $(PROJECTNAME), which can \nbe found in the standard applications of each operating system in the C programming language using structured programming. \nIn addition to basic arithmetic operations such as add/subtract and multiply/divide, \nyou need to supplement the $(PROJECTNAME) with the ability to calculate arithmetic expressions by following the order, \nas well as some mathematical functions (sine, cosine, logarithm, etc.)." \
	> $(PROJECTNAME).dvi

dist:
	tar -czf $(PROJECTNAME).tgz $(PROJECTNAME)

gcov_report:
	$(CC) $(CFLAGS) $(GFLAGS) $(PROJECTNAME)_tests/s21_test.c $(PROJECTNAME)_backend/*.c -o test.out $(LIBS)
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

$(PROJECTNAME).a: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -c
	ar rcs $(PROJECTNAME).a *.o 
	ranlib $(PROJECTNAME).a

tests: $(PROJECTNAME)_tests/s21_test.c $(PROJECTNAME).a
	$(CC) $(CFLAGS) $(PROJECTNAME)_tests/s21_test.c $(PROJECTNAME).a -o test.out $(LIBS)
	./test.out

check:
	@cp ../materials/linters/.clang-format $(PROJECTNAME)_backend/
	@cp ../materials/linters/.clang-format $(PROJECTNAME)_interface/
	@cp ../materials/linters/.clang-format $(PROJECTNAME)_tests/
	clang-format -n $(PROJECTNAME)_interface/*.cpp
	clang-format -n $(PROJECTNAME)_interface/*.h
	clang-format -n $(PROJECTNAME)_backend/*.c
	clang-format -n $(PROJECTNAME)_backend/*.h
