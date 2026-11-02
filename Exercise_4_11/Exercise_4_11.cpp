void bubbleSort(int a[], int size) {
    int hold;
	// swapped 
    // it indicates whether a swap took place
    bool swapped;

    for (int pass = 1; pass < size; pass++) {
        swapped = false;

		// size - pass 
        // With each pass, the number of comparisons decreases by one.
        for (int i = 0; i < size - pass; i++) {

            if (a[i] > a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;

                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}