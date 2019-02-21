function run_test()
{
	time (./lem_in < $1) > output.tmp 2> output_stderr.tmp
	echo "============================================="
	echo "Map:\t" $1
	cat output.tmp | grep ^L | wc -l
	cat output_stderr.tmp | grep real
}

function run_test_display()
{
	echo "============================================="
	echo "Map:\t" $1
	./lem_in < $1
}

make &&
# run_test model/sujet3.map
# run_test model/test/20.map
# run_test model/test/10k.map
run_test_display model/test/err_3_coordinates.map
run_test_display model/test/err_double_start.map
run_test_display model/test/err_duplicate.map
run_test_display model/test/err_empty.map
run_test_display model/test/err_letter_in_coordinate.map
run_test_display model/test/err_link_to_unknown_room.map
run_test_display model/test/err_no_ants.map
run_test_display model/test/err_no_ants2.map
run_test_display model/test/err_no_ants3.map
run_test_display model/test/err_no_end.map
run_test_display model/test/err_no_end2.map
run_test_display model/test/err_no_links.map
run_test_display model/test/err_no_path.map
run_test_display model/test/err_no_rooms.map
run_test_display model/test/err_no_start.map
run_test_display model/test/err_no_start2.map
run_test_display model/test/err_start_end_same.map
run_test_display model/test/err_too_few_ants.map
run_test_display model/test/err_too_many_ants.map
