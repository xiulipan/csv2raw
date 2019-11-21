// SPDX-License-Identifier: BSD-3-Clause
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
	const char *out_file, *in_file;
	FILE *fp_out, *fp_in;
	int opt = 0, ret = 0, i = 0;
	float tmp0;
	int tmp1, tmp2;
	unsigned int line_cnt = 0;
	char linetmp[1024];
	char strtmp[128];
	int *res;

	while ((opt = getopt(argc, argv, "i:o:")) != -1) {
		switch (opt) {
		case 'o':
			out_file = optarg;
			break;
		case 'i':
			in_file = optarg;
			break;
		default:
			break;
		}
	}

	if((fp_in = fopen(in_file, "r")) == NULL) {
		printf("can not open %s!", in_file);
		goto out;
	}

	if((fp_out = fopen(out_file, "wb")) == NULL) {
		printf("can not open %s!", in_file);
		goto out;
	}

	while (!feof(fp_in)) {
		fgets(linetmp, 1024, fp_in);
		line_cnt++;
	}

	fseek(fp_in, 0, 0);

	res = (int *)malloc(sizeof(int) * line_cnt++);

	while (!feof(fp_in)) {
		fgets(linetmp, 1024, fp_in);
		ret = sscanf(linetmp, "%f,%d,%d", &tmp0, &tmp1, &tmp2);
		if (ret == 3) {
			// TODO: now only convert S24 into S32, need other format convertion
			res[i++] = tmp2 << 8;
		}
	}

	ret = fwrite(res, sizeof(int), line_cnt++, fp_out);

	printf("In file is %s with %d line, out file is %s with %d samples\n", in_file, line_cnt, out_file, ret);

out:
	if (fp_in)
		fclose(fp_in);

	if (fp_out)
		fclose(fp_out);

	if (res)
		free(res);

	return 0;
}

