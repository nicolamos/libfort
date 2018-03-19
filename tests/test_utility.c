#include "tests.h"
#include "fort.h"

int set_test_options_for_table(FTABLE *table)
{
    assert(table);
    int status = FT_SUCCESS;
    status |= ft_set_option(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_OPT_BOTTOM_PADDING, 1);
    status |= ft_set_option(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_OPT_TOP_PADDING, 1);
    status |= ft_set_option(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_OPT_LEFT_PADDING, 1);
    status |= ft_set_option(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_OPT_RIGHT_PADDING, 1);
    status |= ft_set_option(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_OPT_EMPTY_STR_HEIGHT, 1);

    assert_true( status == FT_SUCCESS );


    struct ft_border_style brdr_style;
    brdr_style.border_chs.top_border_ch = '-';
    brdr_style.border_chs.separator_ch = '-';
    brdr_style.border_chs.bottom_border_ch = '-';
    brdr_style.border_chs.side_border_ch = '|';
    brdr_style.border_chs.out_intersect_ch = '+';
    brdr_style.border_chs.in_intersect_ch = '+';

    brdr_style.header_border_chs.top_border_ch = '-';
    brdr_style.header_border_chs.separator_ch = '-';
    brdr_style.header_border_chs.bottom_border_ch = '-';
    brdr_style.header_border_chs.side_border_ch = '|';
    brdr_style.header_border_chs.out_intersect_ch = '+';
    brdr_style.header_border_chs.in_intersect_ch = '+';

    brdr_style.hor_separator_char = '=';
    return ft_set_border_style(table, &brdr_style);
}

int set_test_options_as_default()
{
    int status = FT_SUCCESS;

    status |= ft_set_default_option(FT_OPT_MIN_WIDTH, 0);
    status |= ft_set_default_option(FT_OPT_TEXT_ALIGN, RightAligned);

    status |= ft_set_default_option(FT_OPT_BOTTOM_PADDING, 1);
    status |= ft_set_default_option(FT_OPT_TOP_PADDING, 1);
    status |= ft_set_default_option(FT_OPT_LEFT_PADDING, 1);
    status |= ft_set_default_option(FT_OPT_RIGHT_PADDING, 1);
    status |= ft_set_default_option(FT_OPT_EMPTY_STR_HEIGHT, 1);

    assert_true( status == FT_SUCCESS );


    struct ft_border_style brdr_style;
    brdr_style.border_chs.top_border_ch = '-';
    brdr_style.border_chs.separator_ch = '-';
    brdr_style.border_chs.bottom_border_ch = '-';
    brdr_style.border_chs.side_border_ch = '|';
    brdr_style.border_chs.out_intersect_ch = '+';
    brdr_style.border_chs.in_intersect_ch = '+';

    brdr_style.header_border_chs.top_border_ch = '-';
    brdr_style.header_border_chs.separator_ch = '-';
    brdr_style.header_border_chs.bottom_border_ch = '-';
    brdr_style.header_border_chs.side_border_ch = '|';
    brdr_style.header_border_chs.out_intersect_ch = '+';
    brdr_style.header_border_chs.in_intersect_ch = '+';

    brdr_style.hor_separator_char = '=';

    return ft_set_default_border_style(&brdr_style);
}



FTABLE *create_test_int_table(int set_test_opts)
{
    FTABLE *table = NULL;

    table = ft_create_table();
    assert_true( table != NULL );
    if (set_test_opts) {
        assert_true( set_test_options_for_table(table) == FT_SUCCESS);
    }
//        ft_set_table_options(table, &test_table_opts);

    assert_true (table != NULL);

    ft_set_option(table, 0, FT_ANY_COLUMN, FT_OPT_ROW_TYPE, Header);
    int n = ft_printf_ln(table, "%d|%d|%d|%d", 3, 4, 55, 67);

    assert_true( n == 4 );

    assert(ft_write(table, "3") == FT_SUCCESS);
    assert(ft_write(table, "4") == FT_SUCCESS);
    assert(ft_write(table, "55") == FT_SUCCESS);
    assert(ft_write_ln(table, "67") == FT_SUCCESS);

    assert(ft_write(table, "3") == FT_SUCCESS);
    assert(ft_write(table, "4") == FT_SUCCESS);
    assert(ft_write(table, "55") == FT_SUCCESS);
    assert(ft_write_ln(table, "67") == FT_SUCCESS);

    return table;
}