add_library(data_structures
	bitset/bitset.c
	unordered_array_set/unordered_array_set.c
	ordered_array_set/ordered_array_set.c
	vector/vector.c
	vectorVoid/vectorVoid.c
	matrix/matrix.c
)
target_link_libraries(data_structures algorithms)

add_library(data_structures string/string_.h string/string_.c
		# string/tasks/digitToStartTransform.h
	# string/tasks/reverseWords.h
	# string/tasks/replaceDigitsBySpaces.h
	# ...
	# < файл с решением задачи >
	# ...
	# string/tasks/hasPairOfWordsWithEqualLetterSet.h
	# string/tasks/printWordsNonEqualLastWord.h
)

target_link_libraries(project string)