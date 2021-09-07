enum_strings:
	python3.9 ./utils/gen_enum_str_convertion.py

test:
	cmake -S . -B build  && cmake --build build && ctest build