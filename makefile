compile:
	@bam
run:
	@./bam/build/debug/graphicsEngine | tee log
getlog:
	@if [ -f log ]; then cat log; else echo "no log file"; fi
.PHONY: compile run getlog no_compile_run