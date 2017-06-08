INTERPRETER_FILES=$(wildcard lib/interpreter/*)
SUBMISSION_FILES=$(wildcard src/*)

interpreter: $(INTERPRETER_FILES) $(SUBMISSION_FILES)
	@echo "[*] building interpreter"
	@rm -rf ./build
	@mkdir  ./build
	@find   ./src             -mindepth 1 -maxdepth 1 -exec cp {} ./build \;
	@find   ./lib/interpreter -mindepth 1 -maxdepth 1 -exec cp {} ./build \;
	@g++ -std=c++11 ./build/*.cpp -o interpreter

validate: judge reference interpreter
	@INPUT_FILES=$$(echo ./data/*.in); \
	for INPUT_FILE in $$INPUT_FILES; do \
		ANS_FILE=`echo $$INPUT_FILE | sed 's/\.in$$/.ans/'`; \
    if [ ! -f $$ANS_FILE ]; then \
      echo "[*] running reference implementation on $$INPUT_FILE"; \
      ./reference < $$INPUT_FILE > $$ANS_FILE; \
    fi; \
		echo "[*] running $$INPUT_FILE"; \
		rm -rf ./tmp; \
		mkdir  ./tmp; \
		./interpreter < $$INPUT_FILE > ./tmp/student.ans; \
		./judge $$INPUT_FILE $$ANS_FILE ./tmp author_messages < ./tmp/student.ans; \
		if [ "$$?" -ne 42 ]; then \
	    echo "[*] ERROR DETECTED:"; \
	    echo; \
			cat ./tmp/teammessage.txt; \
	    break; \
		fi; \
	done
	@echo "[*] cleaning up";
	@rm -rf ./natch.*;
