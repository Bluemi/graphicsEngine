compile:
	@bam
no_compile_run:
	@./bam/build/debug/graphicsEngine | tee log
run: compile
	@./bam/build/debug/graphicsEngine | tee log
getlog:
	@if [ -f log ]; then cat log; else echo "no log file"; fi
.PHONY: compile run getlog no_compile_run
