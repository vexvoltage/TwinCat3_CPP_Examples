using TwinCAT.Ads;
namespace adsClientVisu
{
    partial class form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbPort = new System.Windows.Forms.TextBox();
            this.tbNetId = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbOutput = new System.Windows.Forms.ListBox();
            this.btStart = new System.Windows.Forms.Button();
            this.btConnect = new System.Windows.Forms.Button();
            this.btRead = new System.Windows.Forms.Button();
            this.btOverwrite = new System.Windows.Forms.Button();
            this.btStop = new System.Windows.Forms.Button();
            this.btReset = new System.Windows.Forms.Button();
            this.tbValue = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // tbPort
            // 
            this.tbPort.Location = new System.Drawing.Point(78, 45);
            this.tbPort.Name = "tbPort";
            this.tbPort.Size = new System.Drawing.Size(134, 20);
            this.tbPort.TabIndex = 0;
            // 
            // tbNetId
            // 
            this.tbNetId.Location = new System.Drawing.Point(78, 19);
            this.tbNetId.Name = "tbNetId";
            this.tbNetId.Size = new System.Drawing.Size(134, 20);
            this.tbNetId.TabIndex = 0;
            this.tbNetId.Text = "127.0.0.1.1.1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "NetID:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Port:";
            // 
            // lbOutput
            // 
            this.lbOutput.FormattingEnabled = true;
            this.lbOutput.Location = new System.Drawing.Point(78, 78);
            this.lbOutput.Name = "lbOutput";
            this.lbOutput.ScrollAlwaysVisible = true;
            this.lbOutput.Size = new System.Drawing.Size(317, 173);
            this.lbOutput.TabIndex = 2;
            this.lbOutput.SelectedIndexChanged += new System.EventHandler(this.lbOutput_SelectedIndexChanged);
            // 
            // btStart
            // 
            this.btStart.Location = new System.Drawing.Point(11, 133);
            this.btStart.Name = "btStart";
            this.btStart.Size = new System.Drawing.Size(56, 23);
            this.btStart.TabIndex = 3;
            this.btStart.Text = "Start";
            this.btStart.UseVisualStyleBackColor = true;
            this.btStart.Click += new System.EventHandler(this.btStart_Click);
            // 
            // btConnect
            // 
            this.btConnect.Location = new System.Drawing.Point(11, 78);
            this.btConnect.Name = "btConnect";
            this.btConnect.Size = new System.Drawing.Size(56, 23);
            this.btConnect.TabIndex = 3;
            this.btConnect.Text = "Connect";
            this.btConnect.UseVisualStyleBackColor = true;
            this.btConnect.Click += new System.EventHandler(this.btConnect_Click);
            // 
            // btRead
            // 
            this.btRead.Location = new System.Drawing.Point(11, 162);
            this.btRead.Name = "btRead";
            this.btRead.Size = new System.Drawing.Size(56, 23);
            this.btRead.TabIndex = 3;
            this.btRead.Text = "Read";
            this.btRead.UseVisualStyleBackColor = true;
            this.btRead.Click += new System.EventHandler(this.btRead_Click);
            // 
            // btOverwrite
            // 
            this.btOverwrite.Location = new System.Drawing.Point(178, 262);
            this.btOverwrite.Name = "btOverwrite";
            this.btOverwrite.Size = new System.Drawing.Size(62, 23);
            this.btOverwrite.TabIndex = 3;
            this.btOverwrite.Text = "Overwrite";
            this.btOverwrite.UseVisualStyleBackColor = true;
            this.btOverwrite.Click += new System.EventHandler(this.btOverwrite_Click);
            // 
            // btStop
            // 
            this.btStop.Location = new System.Drawing.Point(11, 191);
            this.btStop.Name = "btStop";
            this.btStop.Size = new System.Drawing.Size(56, 23);
            this.btStop.TabIndex = 3;
            this.btStop.Text = "Stop";
            this.btStop.UseVisualStyleBackColor = true;
            this.btStop.Click += new System.EventHandler(this.btStop_Click);
            // 
            // btReset
            // 
            this.btReset.Location = new System.Drawing.Point(333, 262);
            this.btReset.Name = "btReset";
            this.btReset.Size = new System.Drawing.Size(62, 23);
            this.btReset.TabIndex = 3;
            this.btReset.Text = "Reset";
            this.btReset.UseVisualStyleBackColor = true;
            this.btReset.Click += new System.EventHandler(this.btReset_Click);
            // 
            // tbValue
            // 
            this.tbValue.Location = new System.Drawing.Point(78, 264);
            this.tbValue.Name = "tbValue";
            this.tbValue.Size = new System.Drawing.Size(94, 20);
            this.tbValue.TabIndex = 4;
            this.tbValue.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 267);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "Value:";
            // 
            // form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(410, 299);
            this.Controls.Add(this.tbValue);
            this.Controls.Add(this.btReset);
            this.Controls.Add(this.btStop);
            this.Controls.Add(this.btOverwrite);
            this.Controls.Add(this.btRead);
            this.Controls.Add(this.btConnect);
            this.Controls.Add(this.btStart);
            this.Controls.Add(this.lbOutput);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbNetId);
            this.Controls.Add(this.tbPort);
            this.Name = "form";
            this.Text = "ADS Client UI";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbPort;
        private System.Windows.Forms.TextBox tbNetId;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox lbOutput;
        
        private TcAdsClient _tcClient;
        private AdsStream adsWriteStream;
        private AdsStream adsReadStream;
        private System.Windows.Forms.Button btStart;
        private System.Windows.Forms.Button btConnect;
        private System.Windows.Forms.Button btRead;
        private System.Windows.Forms.Button btOverwrite;
        private System.Windows.Forms.Button btStop;
        private System.Windows.Forms.Button btReset;
        private System.Windows.Forms.TextBox tbValue;
        private System.Windows.Forms.Label label3;
    }
}

