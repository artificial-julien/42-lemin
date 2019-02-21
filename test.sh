function run_test()
{
	time (./lem_in < $1) > output.tmp 2> output_stderr.tmp
	echo "============================================="
	echo "Map:\t" $1
	cat output.tmp | grep ^L | wc -l
	cat output_stderr.tmp | grep real
}

make &&
run_test model/sujet3.map
run_test model/test/20.map
run_test model/test/10k.map
