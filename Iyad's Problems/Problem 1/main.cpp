#include "header.h"

int main()
{
	LabelGenerator figureNumbers("Figure ", 1);
	LabelGenerator pointNumbers("P", 0);
	FileLabelGenerator fileLabel("Line ", 1, "input.txt");
	LabelGenerator *ptr;

	// Change the variable that ptr points to to choose what type of label use
	ptr = &fileLabel;
	for (int i = 0; i < 5; i++)
		cout << ptr->nextLabel() << endl;

	return EXIT_SUCCESS;
}
