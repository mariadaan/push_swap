int	main(int argc, char *argv[])
{
	if (check_input(argc, argv + 1))
		return (error_msg("Error: non-int arguments", 1));
}