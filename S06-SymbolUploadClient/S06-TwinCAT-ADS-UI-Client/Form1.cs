using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.IO;
using TwinCAT.Ads;


namespace Sample06
{	
    /// <summary>
    /// Summary description for Form1.
    /// </summary>
    public class Form1 : System.Windows.Forms.Form
    {
        private System.Windows.Forms.TreeView treeViewSymbols;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnLoad;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbDatatype;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbIndexGroup;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbIndexOffset;
        private System.Windows.Forms.Button btnFindSymbol;
        private System.Windows.Forms.Button btnReadSymbolInfo;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox tbDatatypeId;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox tbValue;
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;
        private System.Windows.Forms.TextBox tbSymbolname;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox tbSize;
        private System.Windows.Forms.Button btnWrite;		
        private System.Windows.Forms.TextBox tbName;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.CheckBox cbFlat;
    
        private TcAdsSymbolInfoLoader symbolLoader;
        private TcAdsClient adsClient;
        private Button btnWatch;
        private ITcAdsSymbol currentSymbol = null;
        private TextBox tbWatch;
        private TextBox tbWriteWatch;
        private Button btnWriteWatch;
        private GroupBox gbWatch;
        private Label label10;
        private TextBox tbWatchSymbolName;
        private Label label8;
        private Label label11;
        private GroupBox gpCurrentSymbol;
        private Label label12;
        private TextBox tbAdsPort;
        private Label label13;
        private TextBox tbNetID;
       private int notificationHandle = 0;        

        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose( bool disposing )
        {
            if( disposing )
            {
                if (components != null) 
                {
                    components.Dispose();
                }
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.treeViewSymbols = new System.Windows.Forms.TreeView();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label12 = new System.Windows.Forms.Label();
            this.tbAdsPort = new System.Windows.Forms.TextBox();
            this.cbFlat = new System.Windows.Forms.CheckBox();
            this.btnLoad = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.tbDatatype = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.tbSize = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.tbIndexGroup = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tbIndexOffset = new System.Windows.Forms.TextBox();
            this.btnFindSymbol = new System.Windows.Forms.Button();
            this.btnReadSymbolInfo = new System.Windows.Forms.Button();
            this.tbSymbolname = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.tbDatatypeId = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.tbValue = new System.Windows.Forms.TextBox();
            this.btnWrite = new System.Windows.Forms.Button();
            this.tbName = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.tbWriteWatch = new System.Windows.Forms.TextBox();
            this.btnWriteWatch = new System.Windows.Forms.Button();
            this.tbWatch = new System.Windows.Forms.TextBox();
            this.btnWatch = new System.Windows.Forms.Button();
            this.gbWatch = new System.Windows.Forms.GroupBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.tbWatchSymbolName = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.gpCurrentSymbol = new System.Windows.Forms.GroupBox();
            this.label13 = new System.Windows.Forms.Label();
            this.tbNetID = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.gbWatch.SuspendLayout();
            this.gpCurrentSymbol.SuspendLayout();
            this.SuspendLayout();
            // 
            // treeViewSymbols
            // 
            this.treeViewSymbols.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.treeViewSymbols.Location = new System.Drawing.Point(8, 16);
            this.treeViewSymbols.Name = "treeViewSymbols";
            this.treeViewSymbols.Size = new System.Drawing.Size(429, 218);
            this.treeViewSymbols.TabIndex = 0;
            this.treeViewSymbols.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewSymbols_AfterSelect);
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.tbNetID);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.tbAdsPort);
            this.groupBox1.Controls.Add(this.cbFlat);
            this.groupBox1.Controls.Add(this.btnLoad);
            this.groupBox1.Controls.Add(this.treeViewSymbols);
            this.groupBox1.Location = new System.Drawing.Point(8, 8);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(445, 274);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Symbols";
            // 
            // label12
            // 
            this.label12.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(343, 247);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(54, 13);
            this.label12.TabIndex = 4;
            this.label12.Text = "ADS Port:";
            // 
            // tbAdsPort
            // 
            this.tbAdsPort.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbAdsPort.Location = new System.Drawing.Point(395, 244);
            this.tbAdsPort.Name = "tbAdsPort";
            this.tbAdsPort.Size = new System.Drawing.Size(40, 20);
            this.tbAdsPort.TabIndex = 3;
            this.tbAdsPort.Text = "350";
            // 
            // cbFlat
            // 
            this.cbFlat.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cbFlat.Location = new System.Drawing.Point(120, 242);
            this.cbFlat.Name = "cbFlat";
            this.cbFlat.Size = new System.Drawing.Size(72, 24);
            this.cbFlat.TabIndex = 2;
            this.cbFlat.Text = "flat";
            // 
            // btnLoad
            // 
            this.btnLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLoad.Location = new System.Drawing.Point(8, 242);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(104, 23);
            this.btnLoad.TabIndex = 1;
            this.btnLoad.Text = "Load Symbols";
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(13, 149);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(72, 23);
            this.label3.TabIndex = 17;
            this.label3.Text = "Datatype:";
            // 
            // tbDatatype
            // 
            this.tbDatatype.Location = new System.Drawing.Point(93, 149);
            this.tbDatatype.Name = "tbDatatype";
            this.tbDatatype.ReadOnly = true;
            this.tbDatatype.Size = new System.Drawing.Size(144, 20);
            this.tbDatatype.TabIndex = 16;
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(13, 117);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(72, 23);
            this.label9.TabIndex = 15;
            this.label9.Text = "Size:";
            // 
            // tbSize
            // 
            this.tbSize.Location = new System.Drawing.Point(93, 117);
            this.tbSize.Name = "tbSize";
            this.tbSize.ReadOnly = true;
            this.tbSize.Size = new System.Drawing.Size(144, 20);
            this.tbSize.TabIndex = 14;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(13, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 23);
            this.label2.TabIndex = 13;
            this.label2.Text = "Index Group:";
            // 
            // tbIndexGroup
            // 
            this.tbIndexGroup.Location = new System.Drawing.Point(93, 53);
            this.tbIndexGroup.Name = "tbIndexGroup";
            this.tbIndexGroup.ReadOnly = true;
            this.tbIndexGroup.Size = new System.Drawing.Size(144, 20);
            this.tbIndexGroup.TabIndex = 12;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(13, 85);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 23);
            this.label1.TabIndex = 11;
            this.label1.Text = "Index Offset:";
            // 
            // tbIndexOffset
            // 
            this.tbIndexOffset.Location = new System.Drawing.Point(93, 85);
            this.tbIndexOffset.Name = "tbIndexOffset";
            this.tbIndexOffset.ReadOnly = true;
            this.tbIndexOffset.Size = new System.Drawing.Size(144, 20);
            this.tbIndexOffset.TabIndex = 10;
            // 
            // btnFindSymbol
            // 
            this.btnFindSymbol.Location = new System.Drawing.Point(120, 56);
            this.btnFindSymbol.Name = "btnFindSymbol";
            this.btnFindSymbol.Size = new System.Drawing.Size(104, 23);
            this.btnFindSymbol.TabIndex = 18;
            this.btnFindSymbol.Text = "Find Symbol";
            this.btnFindSymbol.Click += new System.EventHandler(this.btnFindSymbol_Click);
            // 
            // btnReadSymbolInfo
            // 
            this.btnReadSymbolInfo.Location = new System.Drawing.Point(8, 56);
            this.btnReadSymbolInfo.Name = "btnReadSymbolInfo";
            this.btnReadSymbolInfo.Size = new System.Drawing.Size(104, 23);
            this.btnReadSymbolInfo.TabIndex = 19;
            this.btnReadSymbolInfo.Text = "Read Symbol Info";
            this.btnReadSymbolInfo.Click += new System.EventHandler(this.btnReadSymbolInfo_Click);
            // 
            // tbSymbolname
            // 
            this.tbSymbolname.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbSymbolname.Location = new System.Drawing.Point(88, 24);
            this.tbSymbolname.Name = "tbSymbolname";
            this.tbSymbolname.Size = new System.Drawing.Size(600, 20);
            this.tbSymbolname.TabIndex = 20;
            this.tbSymbolname.Text = "MAIN.INT32_1";
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.btnReadSymbolInfo);
            this.groupBox2.Controls.Add(this.tbSymbolname);
            this.groupBox2.Controls.Add(this.btnFindSymbol);
            this.groupBox2.Location = new System.Drawing.Point(8, 397);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(697, 88);
            this.groupBox2.TabIndex = 21;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Symbol Info";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(8, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(80, 23);
            this.label4.TabIndex = 21;
            this.label4.Text = "Symbol Name:";
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(13, 181);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(72, 23);
            this.label5.TabIndex = 23;
            this.label5.Text = "Datatype Id:";
            // 
            // tbDatatypeId
            // 
            this.tbDatatypeId.Location = new System.Drawing.Point(93, 181);
            this.tbDatatypeId.Name = "tbDatatypeId";
            this.tbDatatypeId.ReadOnly = true;
            this.tbDatatypeId.Size = new System.Drawing.Size(144, 20);
            this.tbDatatypeId.TabIndex = 22;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(13, 213);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(72, 23);
            this.label6.TabIndex = 25;
            this.label6.Text = "Value:";
            // 
            // tbValue
            // 
            this.tbValue.Location = new System.Drawing.Point(93, 213);
            this.tbValue.Name = "tbValue";
            this.tbValue.Size = new System.Drawing.Size(144, 20);
            this.tbValue.TabIndex = 24;
            // 
            // btnWrite
            // 
            this.btnWrite.Location = new System.Drawing.Point(16, 239);
            this.btnWrite.Name = "btnWrite";
            this.btnWrite.Size = new System.Drawing.Size(221, 23);
            this.btnWrite.TabIndex = 26;
            this.btnWrite.Text = "Write using WriteSymbol";
            this.btnWrite.Click += new System.EventHandler(this.btnWrite_Click);
            // 
            // tbName
            // 
            this.tbName.Location = new System.Drawing.Point(93, 21);
            this.tbName.Name = "tbName";
            this.tbName.ReadOnly = true;
            this.tbName.Size = new System.Drawing.Size(144, 20);
            this.tbName.TabIndex = 27;
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(13, 21);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(72, 23);
            this.label7.TabIndex = 28;
            this.label7.Text = "Name:";
            // 
            // tbWriteWatch
            // 
            this.tbWriteWatch.Location = new System.Drawing.Point(88, 62);
            this.tbWriteWatch.Name = "tbWriteWatch";
            this.tbWriteWatch.Size = new System.Drawing.Size(144, 20);
            this.tbWriteWatch.TabIndex = 32;
            // 
            // btnWriteWatch
            // 
            this.btnWriteWatch.Location = new System.Drawing.Point(238, 60);
            this.btnWriteWatch.Name = "btnWriteWatch";
            this.btnWriteWatch.Size = new System.Drawing.Size(166, 23);
            this.btnWriteWatch.TabIndex = 31;
            this.btnWriteWatch.Text = "Write using Variable Handle";
            this.btnWriteWatch.UseVisualStyleBackColor = true;
            this.btnWriteWatch.Click += new System.EventHandler(this.btnWriteWatch_Click_1);
            // 
            // tbWatch
            // 
            this.tbWatch.Location = new System.Drawing.Point(88, 37);
            this.tbWatch.Name = "tbWatch";
            this.tbWatch.Size = new System.Drawing.Size(144, 20);
            this.tbWatch.TabIndex = 30;
            // 
            // btnWatch
            // 
            this.btnWatch.Location = new System.Drawing.Point(238, 34);
            this.btnWatch.Name = "btnWatch";
            this.btnWatch.Size = new System.Drawing.Size(166, 23);
            this.btnWatch.TabIndex = 29;
            this.btnWatch.Text = "Watch Current Symbol";
            this.btnWatch.UseVisualStyleBackColor = true;
            this.btnWatch.Click += new System.EventHandler(this.btnWatch_Click);
            // 
            // gbWatch
            // 
            this.gbWatch.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gbWatch.Controls.Add(this.label11);
            this.gbWatch.Controls.Add(this.tbWatch);
            this.gbWatch.Controls.Add(this.tbWriteWatch);
            this.gbWatch.Controls.Add(this.btnWatch);
            this.gbWatch.Controls.Add(this.btnWriteWatch);
            this.gbWatch.Controls.Add(this.label10);
            this.gbWatch.Controls.Add(this.tbWatchSymbolName);
            this.gbWatch.Controls.Add(this.label8);
            this.gbWatch.Location = new System.Drawing.Point(8, 291);
            this.gbWatch.Name = "gbWatch";
            this.gbWatch.Size = new System.Drawing.Size(697, 100);
            this.gbWatch.TabIndex = 30;
            this.gbWatch.TabStop = false;
            this.gbWatch.Text = "Watch";
            // 
            // label11
            // 
            this.label11.Location = new System.Drawing.Point(4, 65);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(80, 23);
            this.label11.TabIndex = 33;
            this.label11.Text = "New Value:";
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(5, 39);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(80, 23);
            this.label10.TabIndex = 23;
            this.label10.Text = "Value:";
            // 
            // tbWatchSymbolName
            // 
            this.tbWatchSymbolName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbWatchSymbolName.Location = new System.Drawing.Point(88, 13);
            this.tbWatchSymbolName.Name = "tbWatchSymbolName";
            this.tbWatchSymbolName.Size = new System.Drawing.Size(601, 20);
            this.tbWatchSymbolName.TabIndex = 22;
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(4, 16);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(80, 23);
            this.label8.TabIndex = 22;
            this.label8.Text = "Symbol Name:";
            // 
            // gpCurrentSymbol
            // 
            this.gpCurrentSymbol.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.gpCurrentSymbol.Controls.Add(this.label1);
            this.gpCurrentSymbol.Controls.Add(this.tbSize);
            this.gpCurrentSymbol.Controls.Add(this.tbIndexGroup);
            this.gpCurrentSymbol.Controls.Add(this.tbName);
            this.gpCurrentSymbol.Controls.Add(this.tbDatatype);
            this.gpCurrentSymbol.Controls.Add(this.tbIndexOffset);
            this.gpCurrentSymbol.Controls.Add(this.label7);
            this.gpCurrentSymbol.Controls.Add(this.tbDatatypeId);
            this.gpCurrentSymbol.Controls.Add(this.label2);
            this.gpCurrentSymbol.Controls.Add(this.label5);
            this.gpCurrentSymbol.Controls.Add(this.btnWrite);
            this.gpCurrentSymbol.Controls.Add(this.tbValue);
            this.gpCurrentSymbol.Controls.Add(this.label9);
            this.gpCurrentSymbol.Controls.Add(this.label3);
            this.gpCurrentSymbol.Controls.Add(this.label6);
            this.gpCurrentSymbol.Location = new System.Drawing.Point(459, 8);
            this.gpCurrentSymbol.Name = "gpCurrentSymbol";
            this.gpCurrentSymbol.Size = new System.Drawing.Size(246, 274);
            this.gpCurrentSymbol.TabIndex = 31;
            this.gpCurrentSymbol.TabStop = false;
            this.gpCurrentSymbol.Text = "Current Symbol";
            // 
            // label13
            // 
            this.label13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(200, 247);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(38, 13);
            this.label13.TabIndex = 6;
            this.label13.Text = "NetID:";
            this.label13.Click += new System.EventHandler(this.label13_Click);
            // 
            // tbNetID
            // 
            this.tbNetID.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbNetID.Location = new System.Drawing.Point(238, 244);
            this.tbNetID.Name = "tbNetID";
            this.tbNetID.Size = new System.Drawing.Size(100, 20);
            this.tbNetID.TabIndex = 5;
            this.tbNetID.Text = "127.0.0.1.1.1";
            this.tbNetID.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(708, 493);
            this.Controls.Add(this.gpCurrentSymbol);
            this.Controls.Add(this.gbWatch);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.MinimumSize = new System.Drawing.Size(640, 480);
            this.Name = "Form1";
            this.Text = "Sample06";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.gbWatch.ResumeLayout(false);
            this.gbWatch.PerformLayout();
            this.gpCurrentSymbol.ResumeLayout(false);
            this.gpCurrentSymbol.PerformLayout();
            this.ResumeLayout(false);

        }
        #endregion

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() 
        {
            Application.Run(new Form1());
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            try
            {
                adsClient = new TcAdsClient();
                adsClient.AdsNotification += new AdsNotificationEventHandler(adsClient_AdsNotification);
                adsClient.AdsNotificationEx+=new AdsNotificationExEventHandler(adsClient_AdsNotificationEx);
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        void adsClient_AdsNotification(object sender, AdsNotificationEventArgs e)
        {
            tbWatch.Text = BitConverter.ToString(e.DataStream.ToArray());
        }

        void adsClient_AdsNotificationEx(object sender, AdsNotificationExEventArgs e)
        {
            tbWatch.Text = e.Value.ToString();
        }
        
        private void btnLoad_Click(object sender, System.EventArgs e)
        {
            treeViewSymbols.Nodes.Clear();
            //check adr info
            AmsAddress serverAddress = null;
            try
            {
                // check if port is a hex value
                if (tbAdsPort.Text.StartsWith(("0x")) || tbAdsPort.Text.StartsWith(("0X")))
                {
                    string sHexValue = tbAdsPort.Text.Substring(2);
                    serverAddress = new AmsAddress(tbNetID.Text, Int32.Parse(sHexValue, System.Globalization.NumberStyles.HexNumber));
                }
                // interpret as dec value
                else
                {
                    serverAddress = new AmsAddress(tbNetID.Text, Int32.Parse(tbAdsPort.Text));
                }

            }
            catch
            {
                MessageBox.Show("Invalid AMS NetId " + tbNetID.Text + " or Ams port " + tbAdsPort.Text + "!");
                return;
            }
            //connect
            try
            {
                //orig for just 127.0...: adsClient.Connect(Convert.ToInt32(tbAdsPort.Text));
                adsClient.Connect(serverAddress.NetId, serverAddress.Port);
                symbolLoader = adsClient.CreateSymbolInfoLoader();

                if( !cbFlat.Checked ) 
                {
                    TcAdsSymbolInfo symbol = symbolLoader.GetFirstSymbol(true);
                    while( symbol != null )
                    {
                        treeViewSymbols.Nodes.Add(CreateNewNode(symbol));
                        symbol = symbol.NextSymbol;
                    }	
                }
                else
                {
                    foreach( TcAdsSymbolInfo symbol in symbolLoader )
                    {
                        TreeNode node = new TreeNode(symbol.Name);
                        node.Tag = symbol;
                        treeViewSymbols.Nodes.Add(node);
                    }
                }
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btnReadSymbolInfo_Click(object sender, System.EventArgs e)
        {
            try
            {
                ITcAdsSymbol symbol = adsClient.ReadSymbolInfo(tbSymbolname.Text);
                if( symbol == null)
                {
                    MessageBox.Show("Symbol " + tbSymbolname.Text + " not found");
                    return;
                }
                SetSymbolInfo(symbol);
            }
            catch( Exception err )
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btnFindSymbol_Click(object sender, System.EventArgs e)
        {
            try
            {
                ITcAdsSymbol symbol = symbolLoader.FindSymbol(tbSymbolname.Text);
                if( symbol == null)
                {
                    MessageBox.Show("Symbol " + tbSymbolname.Text + " not found");
                    return;
                }
                SetSymbolInfo(symbol);
            }
            catch( Exception err )
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btnWrite_Click(object sender, System.EventArgs e)
        {
            try
            {
                if( currentSymbol != null )
                    adsClient.WriteSymbol(currentSymbol, tbValue.Text);
            }
            catch(Exception err)
            {
                MessageBox.Show("Unable to write Value. " + err.Message);
            }
        }
        
        private void treeViewSymbols_AfterSelect(object sender, System.Windows.Forms.TreeViewEventArgs e)
        {
            if( e.Node.Text.Length > 0 )
            {
                if( e.Node.Tag is ITcAdsSymbol)
                {
                    SetSymbolInfo((ITcAdsSymbol)e.Node.Tag);
                }
            }
        }

        private void btnWatch_Click(object sender, EventArgs e)
        {
            DeleteCurrentNotification();
            string symbolName;
            CreateCurrentNotification(out symbolName);
            tbWatchSymbolName.Text = symbolName;
            
        }

        private void btnWriteWatch_Click(object sender, EventArgs e)
        {
            WriteViaVariableHandle();
        }
        
        private TreeNode CreateNewNode(TcAdsSymbolInfo symbol)
        {
            TreeNode node = new TreeNode(symbol.Name);
            node.Tag = symbol;
            TcAdsSymbolInfo subSymbol = symbol.FirstSubSymbol;
            while( subSymbol != null )
            {
                node.Nodes.Add(CreateNewNode(subSymbol));
                subSymbol = subSymbol.NextSymbol;
            }
            return node;
        }

        private void SetSymbolInfo(ITcAdsSymbol symbol)
        {
            currentSymbol = symbol;
            tbName.Text = symbol.Name.ToString();
            tbIndexGroup.Text = symbol.IndexGroup.ToString("X");
            tbIndexOffset.Text = symbol.IndexOffset.ToString("X");
            tbSize.Text = symbol.Size.ToString();
            tbDatatype.Text = symbol.Type;
            tbDatatypeId.Text = symbol.Datatype.ToString();
            try
            {
                tbValue.Text = adsClient.ReadSymbol(symbol).ToString();
            }
            catch( AdsDatatypeNotSupportedException err )
            {
                tbValue.Text = err.Message;
            }
            catch(Exception err)
            {
                MessageBox.Show("Unable to read Symbol Info. " + err.Message); 
            }
        }

        private Type GetTypeForDataTypeId(AdsDatatypeId id)
        {
            switch (id)
            {
                case AdsDatatypeId.ADST_INT16: return typeof(Int16);
                case AdsDatatypeId.ADST_INT32: return typeof(Int32);
                case AdsDatatypeId.ADST_REAL32: return typeof(Single); 
                case AdsDatatypeId.ADST_REAL64: return typeof(Double); 
                case AdsDatatypeId.ADST_INT8: return typeof(SByte);
                case AdsDatatypeId.ADST_UINT8: return typeof(Byte);
                case AdsDatatypeId.ADST_UINT16: return typeof(UInt16);
                case AdsDatatypeId.ADST_UINT32: return typeof(UInt32);
                case AdsDatatypeId.ADST_INT64: return typeof(Int64);
                case AdsDatatypeId.ADST_UINT64: return typeof(UInt64);
                case AdsDatatypeId.ADST_BIT: return typeof(Byte); 
                case AdsDatatypeId.ADST_STRING: 
                case AdsDatatypeId.ADST_WSTRING:
                case AdsDatatypeId.ADST_REAL80: 
                case AdsDatatypeId.ADST_MAXTYPES:
                case AdsDatatypeId.ADST_BIGTYPE:
                case AdsDatatypeId.ADST_VOID:
                default:
                    throw new NotSupportedException(String.Format("AdsDataTypeId={0} not supported", id.ToString()));
            }
        }

        private object GetObjectForTypeId(AdsDatatypeId id, string value)
        {
            switch (id)
            {
                case AdsDatatypeId.ADST_INT16: return Convert.ToInt16(value);
                case AdsDatatypeId.ADST_INT32: return Convert.ToInt32(value);
                case AdsDatatypeId.ADST_REAL32: return Convert.ToSingle(value);
                case AdsDatatypeId.ADST_REAL64: return Convert.ToDouble(value);
                case AdsDatatypeId.ADST_INT8: return Convert.ToSByte(value);
                case AdsDatatypeId.ADST_UINT8: return Convert.ToByte(value);
                case AdsDatatypeId.ADST_UINT16: return Convert.ToUInt16(value);
                case AdsDatatypeId.ADST_UINT32: return Convert.ToUInt32(value);
                case AdsDatatypeId.ADST_INT64: return Convert.ToInt64(value);
                case AdsDatatypeId.ADST_UINT64: return Convert.ToUInt64(value);
                case AdsDatatypeId.ADST_BIT: return Convert.ToByte(value);
                case AdsDatatypeId.ADST_STRING:
                case AdsDatatypeId.ADST_WSTRING:
                case AdsDatatypeId.ADST_REAL80:
                case AdsDatatypeId.ADST_MAXTYPES:
                case AdsDatatypeId.ADST_BIGTYPE:
                case AdsDatatypeId.ADST_VOID:
                default:
                    throw new NotSupportedException(String.Format("AdsDataTypeId={0} not supported", id.ToString()));
            }

        }

        private void DeleteCurrentNotification()
        {
            try
            {
                if (this.notificationHandle != 0)
                {
                    adsClient.DeleteDeviceNotification(this.notificationHandle);
                    this.notificationHandle = 0;
                }
            }
            catch(Exception err)
            {
                MessageBox.Show("Failed to delete notificationHandle. " + err.Message); 
            }
        }

        private void CreateCurrentNotification(out string symbolName)
        {
            symbolName = null;
            try
            {
                if (currentSymbol != null)
                {
                    this.notificationHandle =
                        adsClient.AddDeviceNotificationEx
                        (
                            currentSymbol.IndexGroup,
                            currentSymbol.IndexOffset,
                            AdsTransMode.OnChange, 0, 0,
                            currentSymbol,
                            GetTypeForDataTypeId(currentSymbol.Datatype)
                        );
                    symbolName = currentSymbol.Name;
                }
            }
            catch (Exception err)
            {
                MessageBox.Show("Failed to create notificationHandle. " + err.Message);
            }
        }

        private void WriteViaVariableHandle()
        {
            try
            {
                if (currentSymbol != null)
                {
                    int varHdl = adsClient.CreateVariableHandle(currentSymbol.Name);
                    if (varHdl != 0)
                    {
                        adsClient.WriteAny(varHdl, GetObjectForTypeId(currentSymbol.Datatype, tbWriteWatch.Text));
                        adsClient.DeleteVariableHandle(varHdl);
                    }
                }
            }
            catch (Exception err)
            {
                MessageBox.Show("Failed to write with variable handle. " + err.Message);
            }
        }

        private void btnWriteWatch_Click_1(object sender, EventArgs e)
        {
            WriteViaVariableHandle();
        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

    }


}
