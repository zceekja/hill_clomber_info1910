###############################################
# C
###############################################

CC := gcc
CFLAGS := -Wall -Werror

###############################################
# Detect files and set paths accordingly
###############################################

LIBDIR := lib
SRCDIR := src
BUILDDIR := build

SRCFILES := $(wildcard ${SRCDIR}/*.c)
OBJFILES := $(patsubst ${SRCDIR}/%.c, ${BUILDDIR}/%.o, ${SRCFILES})

LINK := -lm

LIBS := -I${LIBDIR} -lm

##################################################
# TEST BUILDER
# DO NOT MODIFY THE FOLLOWING BLOCK
# YOU MIGHT BREAK THE AUTO-MARKER
# This is how we might build our tests
# If you can run `make test` and the test cases are built
# then you should be in a good position with the make file
###################################################

TEST_DIR := test
TEST_CASE_DIR := ${TEST_DIR}/test_cases
TEST_SRC_DIR := ${TEST_DIR}/src
TEST_LIB_DIR := ${TEST_DIR}/lib
TEST_BUILD_DIR := ${BUILDDIR}/tests

TEST_LIBS := -I${TEST_LIB_DIR}

TEST_SRCFILES := $(wildcard ${TEST_SRC_DIR}/*.c)
TEST_OBJFILES := $(patsubst ${TEST_SRC_DIR}/%.c, ${TEST_BUILD_DIR}/%.o, ${TEST_SRCFILES})

TEST_CASE_FILES := $(wildcard ${TEST_CASE_DIR}/*.c)
TEST_CASES := $(patsubst ${TEST_CASE_DIR}/%.c, ${TEST_DIR}/%, ${TEST_CASE_FILES})
TEST_CASE_PRO := $(wildcard ${TEST_DIR}/auto*)
MKDIR_P = mkdir -p

###############################################
# Compile files
###############################################

all: tests

.PHONY: all
.PHONY: run_tests
.PHONY: tests
.PHONY: clean

#################
# Tests
# DO NOT MODIFY THE FOLLOWING BLOCK
# YOU MIGHT BREAK THE AUTO-MARKER
#################

tests: ${BUILDDIR} ${TEST_BUILD_DIR} ${TEST_CASES}

${TEST_DIR}/% : ${TEST_CASE_DIR}/%.c ${TEST_OBJFILES} ${OBJFILES}
	@echo "[Building Test Case]" $@
	${CC} ${CFLAGS} ${LIBS} ${TEST_LIBS} -o $@ $^ ${LINK}

${TEST_BUILD_DIR}/%.o: ${TEST_SRC_DIR}/%.c
	@echo "[Building Test]" $@
	${CC} ${CFLAGS} ${LIBS} ${TEST_LIBS} -c -o $@ $^

#################
# Creates the build directories we need
# You may add other build directories
# But it is essential that the climber.o file
# Is found at build/climber.o
#################

${BUILDDIR}:
	${MKDIR_P} ${BUILDDIR}

${TEST_BUILD_DIR}:
	${MKDIR_P} ${TEST_BUILD_DIR}

${OBJFILES}:

${BUILDDIR}/%.o : ${SRCDIR}/%.c
	${CC} ${CFLAGS} ${LIBS} -c -o $@ $^
#################


#run test
run_tests:
	for i in ${TEST_CASE_PRO}; do \
		./$$i ; \
	done

#################


clean:
	rm -f ${BUILDDIR}/*.o *.out
	rm -f ${TEST_BUILD_DIR}/*.o *.out
	rmdir ${TEST_BUILD_DIR}
	rmdir ${BUILDDIR}
	rm ${TEST_CASES}

echo:
	@echo ${SRCFILES}
	@echo ${OBJFILES}
	@echo ${TEST_CASE_PRO}
