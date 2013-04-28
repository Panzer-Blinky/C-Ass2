
 int main (void)
 {
    /* Loop until user exits */
    do
    {
        /* Print menu */
        printf("\nMain Menu:\n");
        printf("1) Display Customer\n");
        printf("2) Add Customer\n");
        printf("3) Display Stock\n");
        printf("4) Add Stock\n");
        printf("5) Make Sale\n");
        printf("6) Sales Log\n");
        printf("7) Delete Record\n");
        printf("8) Save & Exit\n");
        printf("9) Exit\n");
        printf("\n");
        printf("Select your option (1-9): \t");

        /* Get input from user */
        fgets(input, EXTRA_SPACES, stdin);

        /* Convert to integer */
        option = atoi(input);

        /* Check for valid option (1 to 9) */
        if(option > 9 || option < 1)
        {
            printf("Please select an option between 1 and 9.");
            printf("\n");
        }

        /* Clear buffer to allow future input */
        readRestOfLine();

        /* Switch statement to process input */
        switch(option)
        {
            case 1: printf("Option 1 selected");
                    break;

            case 2: printf("Option 2 selected");
                    break;

            case 3: printf("Option 3 selected");
                    break;

            case 4: printf("Option 4 selected");
                    break;

            case 5: printf("Option 5 selected");
                    break;

            case 6: printf("Option 6 selected");
                    break;

            case 7: printf("Option 7 selected");
                    break;

            case 8: printf("Option 8 selected");
                    break;

            case 9: return EXIT_SUCCESS;

        }
    } while(option != 7);

   return EXIT_SUCCESS;
}
