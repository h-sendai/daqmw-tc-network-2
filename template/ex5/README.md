(�ơ���)�ե�������ɤ�ǥǥ�����
================================

�½��˻Ȥ��ܡ��ɤ���Ȥä��ǡ�����ǥ����ɤ���롼�����񤯡�

�ǡ����ե����ޥåȤ�doc/raw-data-packet-format.pdf�ˤ��롣

�إå����ȡ��ǡ������ˤ狼��Ƥ��롣
�إå�����Ĺ����12�Х��ȤǸ���Ǥ��롣���Τʤ��˼���³���ǡ�������
Ĺ�����񤤤Ƥ���(�Х��Ȥ�ñ��)������¾�إå��ˤ�

* �ǡ���������(0xf) (¾�Υǡ����ѥ��åȤȸ�ʬ����Τ���Ū)
* Word length (2) (1�ȥꥬ1�����ͥ�1������ɥ��ǡ����ΥХ��ȥ�����)
* # of Ch (16) (�����ͥ��)
* �ǡ���Ĺ
* �ȥꥬ��������� (0���ǽ顣�ȥꥬ���������뤴�Ȥ�1�Ť�������)

�ξ������äƤ���ΤǤ������Ф���ʣ���Х��Ȥǹ����������ͤϤ������
�ͥåȥ���Х��ȥ������ˤʤäƤ���Τǡ�PC�ǰ����ˤ��Ѵ���ɬ�פˤʤ롣

�ץ�������template/read_file_decode�ˤ��뤬���ǥ�������ʬ�Υ᥽�åɤ�
�񤤤Ƥʤ��ΤǤ�������뤳�ȡ�

�Ǥ����ǥ����ɥץ������Ϻǽ�Ū��DAQ-Middleware����ݡ��ͥ�Ȥ��Ȥ߹��ळ�Ȥˤʤ롣

����ץ�ǡ�����bs/sample.dat�ˤ��롣���Υե�����Υǡ�������ǥ����ɤ���
trg: XXX ch: XXX window: XXX data: XXX
���¤٤���Τ�bs/ascii.sample�Ȥ��Ƥ����Ƥ���ΤǼ�ʬ�ǽ񤤤��ץ�������OK��
�ɤ����Ϥ����Ʊ���ե����ޥåȤǽ��Ϥ���褦�ˤ�����Ӥ��뤳�Ȥǲ�ǽ�Ǥ��롣
��ӤˤϤ��Ȥ���diff�ץ�������Ȥ��ȵ���Ū�ˤǤ��롣

    diff -u file_a file_b

�㤤���ʤ���Фʤˤ���Ϥ���ʤ���